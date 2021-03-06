INCLUDE_DIRECTORIES(
    ${STM32_USBSTDLib_DIR}/Libraries/CMSIS/Device/ST/STM32F4xx/Include
    ${STM32_USBSTDLib_DIR}/Libraries/CMSIS/Include/
)

SET(ASM_SOURCES
    ${STM32_USBSTDLib_DIR}/Libraries/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc_ride7/startup_stm32f4xx.s
)

SET(CMSIS_LINKER_SCRIPT ${CMAKE_CURRENT_LIST_DIR}/stm32_flash.ld.in)

FUNCTION(STM32F4XX_SET_PARAMS FLASH_SIZE RAM_SIZE MIN_STACK_SIZE MIN_HEAP_SIZE EXT_RAM_SIZE FLASH_ORIGIN RAM_ORIGIN EXT_RAM_ORIGIN)
    CONFIGURE_FILE(${CMSIS_LINKER_SCRIPT} ${CMAKE_CURRENT_BINARY_DIR}/stm32_flash.ld)
ENDFUNCTION(STM32F4XX_SET_PARAMS)

FUNCTION(STM32F4XX_SET_PARAMS FLASH_SIZE RAM_SIZE)
    SET(FLASH_SIZE ${FLASH_SIZE})
    SET(RAM_SIZE ${RAM_SIZE})
    SET(MIN_STACK_SIZE "0x200")
    SET(MIN_HEAP_SIZE "0")
    SET(EXT_RAM_SIZE "0K")
    SET(FLASH_ORIGIN "0x08000000")
    SET(RAM_ORIGIN "0x20000000")
    SET(EXT_RAM_ORIGIN "0x60000000")
    CONFIGURE_FILE(${CMSIS_LINKER_SCRIPT} ${CMAKE_CURRENT_BINARY_DIR}/stm32_flash.ld)
ENDFUNCTION(STM32F4XX_SET_PARAMS)

set_source_files_properties(${ASM_SOURCES} PROPERTIES COMPILE_FLAGS "-x assembler-with-cpp")

SET(CSP_SOURCES ${CSP_SOURCES} ${ASM_SOURCES})