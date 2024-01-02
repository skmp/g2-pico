add_executable(g2_modem)

pico_generate_pio_header(g2_modem ${CMAKE_CURRENT_LIST_DIR}/g2_modem.pio)

target_sources(g2_modem PRIVATE g2_modem.c)

target_link_libraries(g2_modem PRIVATE
        pico_stdlib
        hardware_pio
        )

pico_add_extra_outputs(g2_modem)
