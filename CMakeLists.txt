# cmake -------------------------------------------------------------------------------------------
cmake_minimum_required( VERSION 3.2.0 )

# AEON::Graphics ----------------------------------------------------------------------------------
set( GRAPHICS_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib )
set( GRAPHICS_INC ${CMAKE_CURRENT_SOURCE_DIR}/inc )
set( GRAPHICS_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src )

add_library( aeon-graphics STATIC
    ${GRAPHICS_SRC}/Viewport.cpp
    ${GRAPHICS_SRC}/Window.cpp
)

#if( NOT PROJECT_IS_TOP_LEVEL )
#  add_library( ${PROJECT_NAME}::graphics ALIAS graphics )
#endif()

#target_precompile_headers( aeon-graphics PRIVATE ${HEADERS} ${STD_HEADERS} )

target_include_directories( aeon-graphics 
    PUBLIC
        $<BUILD_INTERFACE:${GRAPHICS_INC}>
	    $<INSTALL_INTERFACE:inc>
)
target_link_libraries( aeon-graphics PRIVATE aeon-base )

if( WIN32 )
    target_link_libraries( aeon-graphics PRIVATE aeon-platform-windows )
endif()

if( TARGET aeon-platform-vulkan )
    target_link_libraries( aeon-graphics PRIVATE aeon-platform-vulkan )
endif()