if(IDF_VERSION_MAJOR GREATER_EQUAL 4)
    idf_component_register(
        SRCS
            ruuvi_board_defaults.h
            ruuvi_board_gateway.h
            ruuvi_board_gwesp.h
            ruuvi_board_gwnrf.h
            ruuvi_board_kaarle.h
            ruuvi_board_kalervo.h
            ruuvi_board_keijo.h
            ruuvi_board_pca10040.h
            ruuvi_board_pca10056e.h
            ruuvi_board_rauno.h
            ruuvi_board_ruuvitag_b.h
            ruuvi_boards.h
        INCLUDE_DIRS "."
        )
else()
    set(COMPONENT_ADD_INCLUDEDIRS src)
    register_component()
endif()
