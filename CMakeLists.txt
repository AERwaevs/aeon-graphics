# cmake -------------------------------------------------------------------------------------------
cmake_minimum_required( VERSION 3.20 )

# Graphics ----------------------------------------------------------------------------------
set( GRAPHICS_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib )
set( GRAPHICS_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc )
set( GRAPHICS_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src )

set( GRAPHICS_HEADER
    ${GRAPHICS_INC_DIR}/Graphics/Viewport.h
    ${GRAPHICS_INC_DIR}/Graphics/Window.h
    ${GRAPHICS_INC_DIR}/Events/WindowEvents.h

    ${GRAPHICS_INC_DIR}/Graphics/VulkanViewport.h
    ${GRAPHICS_INC_DIR}/Graphics/VulkanRenderer.h
    ${GRAPHICS_INC_DIR}/Graphics/RenderGraph.h
    
)

set( GRAPHICS_SOURCE 
    ${GRAPHICS_SRC_DIR}/VulkanViewport.cpp
    ${GRAPHICS_SRC_DIR}/VulkanRenderer.cpp
    ${GRAPHICS_SRC_DIR}/RenderGraph.cpp
    
    ${GRAPHICS_SRC_DIR}/Renderer.cpp
    ${GRAPHICS_SRC_DIR}/Viewport.cpp
    ${GRAPHICS_SRC_DIR}/Window.cpp
)

# gfx module --------------------------------------------------------------------------------------
add_library( graphics SHARED ${GRAPHICS_SOURCE} )
target_include_directories( graphics PUBLIC
    $<BUILD_INTERFACE:${GRAPHICS_INC_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_link_libraries( graphics
    PUBLIC
        base
        $<$<BOOL:${WIN32}>:win32>
        #$<$<BOOL:${LINUX}>:linux>
        $<$<BOOL:${ANDROID}>:android>
        $<$<BOOL:${IOS}>:ios>
        $<$<AND:$<BOOL:${APPLE}>,$<NOT:$<BOOL:${IOS}>>>:macos>
        $<$<TARGET_EXISTS:vulkan>:vulkan>
)
add_library( aer::gfx ALIAS graphics )