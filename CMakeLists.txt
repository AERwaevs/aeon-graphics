add_library( aeon-graphics 
    STATIC
    Viewport.cpp
    Window.cpp
)
add_dependencies( aeon-graphics
    aeon-base
    glad_gl46_vk12
)

set_target_properties( aeon-graphics
    PROPERTIES
        POSITION_INDEPENDENT_CODE TRUE
)

target_precompile_headers( aeon-graphics 
    REUSE_FROM
        aeon-base
)
target_link_libraries( aeon-graphics
    PUBLIC
        aeon-base
        glad_gl46_vk12
)

target_include_directories( aeon-graphics
    PRIVATE
        ${AEON_DIR}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)