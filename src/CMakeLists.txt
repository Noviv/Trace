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
	file(GLOB_RECURSE Trace_HEADERS "include/*.h")

	link_directories(${PCAP_LIBRARY})
	add_executable(Trace ${Trace_SOURCES} ${Trace_HEADERS})
	include_directories(${PCAP_INCLUDE_DIR})
	include_directories("include/")
	target_link_libraries(Trace Packet.lib wpcap.lib ws2_32.lib)
else()
	message(FATAL_ERROR "Trace does not support Linux development!")
endif()