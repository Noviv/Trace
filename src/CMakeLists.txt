cmake_minimum_required(VERSION 2.8)
if (POLICY CMP0043)
	cmake_policy(SET CMP0043 OLD)
endif()
project(Trace)

#check windows
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	#check WinPCAP
	if (EXISTS $ENV{PCAP_ROOT_DIR})
		set(PCAP_INCLUDE_DIR $ENV{PCAP_ROOT_DIR}/Include)
		set(PCAP_LIBRARY $ENV{PCAP_ROOT_DIR}/Lib)
	else()
		message(FATAL_ERROR "Could not find WinPCAP!"
		"\nInstall the WinPCAP dev kit and make a new environment variable"
		" PCAP_ROOT_DIR referencing that directory.")
	endif()
	
	#check wxWidgets
	if (EXISTS $ENV{WXWIDGETS_ROOT_DIR})
		set(wxWidgets_INCLUDE_DIRS $ENV{WXWIDGETS_ROOT_DIR}/include)
		set(wxWidgets_LIBRARIES $ENV{WXWIDGETS_ROOT_DIR}/lib/vc_lib)
	else()
		message(FATAL_ERROR "Could not find wxWidgets!"
		"\nInstall the wxWidgets dev kit and make a new environment variable"
		" WXWIDGETS_ROOT_DIR referencing that directory.")
	endif()
	
	mark_as_advanced(
		wxWidgets_CONFIGURATION
		wxWidgets_LIB_DIR
		wxWidgets_ROOT_DIR
		wxWidgets_wxrc_EXECUTABLE
	)

	#sources
	file(GLOB_RECURSE Trace_SOURCES "src/*.cpp")
	source_group("Sources" FILES ${Trace_SOURCES})
	
	#headers
	file(GLOB_RECURSE Trace_HEADERS "include/*.h")
	source_group("Headers" FILES ${Trace_HEADERS})
	
	#resources
	file(GLOB_RECURSE Trace_RES_H "res/*.h")
	file(GLOB_RECURSE Trace_RES_RC "res/*.rc")
	source_group("Resources" FILES ${Trace_RES_H} ${Trace_RES_RC})
	
	#wxWidgets
	find_package(wxWidgets COMPONENTS core base REQUIRED)
	include(${wxWidgets_USE_FILE})
	
	#finish visual studio
	link_directories(${PCAP_LIBRARY})
	add_executable(Trace ${Trace_SOURCES} ${Trace_HEADERS} ${Trace_RES_H} ${Trace_RES_RC})
	include_directories(${PCAP_INCLUDE_DIR})
	include_directories("include/")
	target_link_libraries(Trace Packet.lib wpcap.lib ws2_32.lib ${wxWidgets_LIBRARIES})
	
	#definitions
	set_target_properties(Trace PROPERTIES LINK_FLAGS "/ENTRY:WinMainCRTStartup")
else()
	message(FATAL_ERROR "Trace only supports Windows development!")
endif()