cmake_minimum_required( VERSION 3.2.0 )

# cmake -------------------------------------------------------------------------------------------
set( GRAPHICS_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib )
set( GRAPHICS_INC ${CMAKE_CURRENT_SOURCE_DIR}/inc )
set( GRAPHICS_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src )

set( CMAKE_CXX_STANDARD          20  )
set( CMAKE_CXX_STANDARD_REQUIRED ON  )
set( CMAKE_CXX_EXTENSIONS        OFF )
# AEON::Graphics ----------------------------------------------------------------------------------
add_library( aeon-graphics STATIC
    ${GRAPHICS_SRC}/Viewport.cpp
    ${GRAPHICS_SRC}/Window.cpp
)

add_dependencies( aeon-graphics
    aeon-base
)

target_link_libraries( aeon-graphics
    PRIVATE
        aeon-base
)

target_include_directories( aeon-graphics
    PUBLIC
        ${GRAPHICS_INC}
    PRIVATE
        ${BASE_INC}
)

target_precompile_headers( aeon-graphics PRIVATE ${HEADERS} ${STD_HEADERS} )

if( WIN32 )
    target_link_libraries( aeon-graphics PUBLIC aeon-platform-windows )
endif()