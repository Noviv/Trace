cmake_minimum_required(VERSION 2.8)
project(Trace)

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	if (EXISTS $ENV{PCAP_ROOT_DIR})
		set(PCAP_INCLUDE_DIR $ENV{PCAP_ROOT_DIR}\\Include)
		set(PCAP_LIBRARY $ENV{PCAP_ROOT_DIR}\\Lib)
	else()
		message(FATAL_ERROR "Could not find WinPCAP!"
		"\nInstall the WinPCAP dev kit and make a new environment variable"
		" PCAP_ROOT_DIR referencing that directory.")
	endif()

	include(FindPackageHandleStandardArgs)
	find_package_handle_standard_args(PCAP DEFAULT_MSG
		PCAP_LIBRARY
		PCAP_INCLUDE_DIR
	)

	include(CheckCSourceCompiles)
	set(CMAKE_REQUIRED_LIBRARIES ${PCAP_LIBRARY})
	check_c_source_compiles("int main() { return 0; }" PCAP_LINKS_SOLO)
	set(CMAKE_REQUIRED_LIBRARIES)

	include(CheckFunctionExists)
	set(CMAKE_REQUIRED_LIBRARIES ${PCAP_LIBRARY})
	check_function_exists(pcap_get_pfring_id HAVE_PF_RING)
	set(CMAKE_REQUIRED_LIBRARIES)

	mark_as_advanced(
		PCAP_ROOT_DIR
		PCAP_INCLUDE_DIR
		PCAP_LIBRARY
	)

	file(GLOB_RECURSE Trace_SOURCES "src/*.cpp")
	file(GLOB_RECURSE Trace_HEADERS "src/include/*.h")

	link_directories(${PCAP_LIBRARY})
	add_executable(Trace ${Trace_SOURCES} ${Trace_HEADERS})
	include_directories(${PCAP_INCLUDE_DIR})
else()
	find_path(PCAP_ROOT_DIR
		NAMES include/pcap.h
	)

	find_path(PCAP_INCLUDE_DIR
		NAMES pcap.h
		HINTS ${PCAP_ROOT_DIR}/include
	)

	find_library(PCAP_LIBRARY
		NAMES pcap
		HINTS ${PCAP_ROOT_DIR}/lib
	)

	include(FindPackageHandleStandardArgs)
	find_package_handle_standard_args(PCAP DEFAULT_MSG
		PCAP_LIBRARY
		PCAP_INCLUDE_DIR
	)

	include(CheckCSourceCompiles)
	set(CMAKE_REQUIRED_LIBRARIES ${PCAP_LIBRARY})
	check_c_source_compiles("int main() { return 0; }" PCAP_LINKS_SOLO)
	set(CMAKE_REQUIRED_LIBRARIES)

	if (NOT PCAP_LINKS_SOLO)
		find_package(Threads)
		if (THREADS_FOUND)
			set(CMAKE_REQUIRED_LIBRARIES ${PCAP_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
			check_c_source_compiles("int main() { return 0; }" PCAP_NEEDS_THREADS)
			set(CMAKE_REQUIRED_LIBRARIES)
		endif ()
		if (THREADS_FOUND AND PCAP_NEEDS_THREADS)
			set(_tmp ${PCAP_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
			list(REMOVE_DUPLICATES _tmp)
			set(PCAP_LIBRARY ${_tmp}
				CACHE STRING "Libraries needed to link against libpcap" FORCE)
		else ()
			message(FATAL_ERROR "Couldn't determine how to link against libpcap")
		endif ()
	endif ()

	include(CheckFunctionExists)
	set(CMAKE_REQUIRED_LIBRARIES ${PCAP_LIBRARY})
	check_function_exists(pcap_get_pfring_id HAVE_PF_RING)
	set(CMAKE_REQUIRED_LIBRARIES)

	mark_as_advanced(
		PCAP_ROOT_DIR
		PCAP_INCLUDE_DIR
		PCAP_LIBRARY
	)
endif()