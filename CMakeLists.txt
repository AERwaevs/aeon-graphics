# cmake -------------------------------------------------------------------------------------------
cmake_minimum_required( VERSION 3.2.0 )

# AEON::Graphics ----------------------------------------------------------------------------------
set( GRAPHICS_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib )
set( GRAPHICS_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc )
set( GRAPHICS_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src )

set( GRAPHICS_HEADER
    ${GRAPHICS_INC_DIR}/Graphics/Viewport.h
    ${GRAPHICS_INC_DIR}/Graphics/Window.h
)

set( GRAPHICS_SOURCE 
    ${GRAPHICS_SRC_DIR}/Viewport.cpp
    ${GRAPHICS_SRC_DIR}/Window.cpp
)

add_library( aeon-graphics STATIC
    ${GRAPHICS_HEADER}
    ${GRAPHICS_SOURCE}
)

#if( NOT PROJECT_IS_TOP_LEVEL )
#  add_library( ${PROJECT_NAME}::graphics ALIAS graphics )
#endif()

#target_precompile_headers( aeon-graphics PRIVATE ${HEADERS} ${STD_HEADERS} )

target_include_directories( aeon-graphics 
    PUBLIC
        $<BUILD_INTERFACE:${GRAPHICS_INC_DIR}>
	    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_link_libraries( aeon-graphics PRIVATE aeon-base )

if( WIN32 )
    target_link_libraries( aeon-graphics PRIVATE aeon-platform-windows )
endif()

if( TARGET aeon-platform-vulkan )
    target_link_libraries( aeon-graphics PRIVATE aeon-platform-vulkan )
endif()