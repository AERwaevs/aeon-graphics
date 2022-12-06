add_library( aeon-graphics STATIC Renderer.cpp )
add_dependencies( aeon-graphics
    aeon-base
    aeon-platform-vulkan
)

#add_custom_command( aeon-graphics 
#    PRE_BUILD
#    COMMAND 
#)

set_target_properties(      aeon-graphics   PROPERTIES  POSITION_INDEPENDENT_CODE   TRUE )

target_link_libraries( aeon-graphics
    PUBLIC
        aeon-base
        aeon-platform-vulkan
)

#target_precompile_headers(  aeon-graphics REUSE_FROM  aeon-base                     )
target_include_directories( aeon-graphics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )