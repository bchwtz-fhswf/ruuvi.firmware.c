if(IDF_VERSION_MAJOR GREATER_EQUAL 4)
    idf_component_register(
        SRCS "src/ruuvi_endpoint_ca_uart.c"
        INCLUDE_DIRS "src"
        )
elseif(CMAKE_PROJECT_NAME STREQUAL "ruuvi.node_nrf91.c")
    zephyr_include_directories(src)
    target_sources(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/ruuvi_endpoints.c)
    target_sources(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/ruuvi_endpoint_3.c)
    target_sources(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/ruuvi_endpoint_5.c)
    target_sources(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/ruuvi_endpoint_ca_uart.c)
    target_sources(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/ruuvi_endpoint_ibeacon.c)
else()
    set(COMPONENT_SRCDIRS src)
    set(COMPONENT_ADD_INCLUDEDIRS src)
    register_component()
endif()
