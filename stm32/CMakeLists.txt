set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)
project(fatpp C CXX ASM)
cmake_minimum_required(VERSION 3.5.0)

function(disassemble name target function)
    add_custom_target(${name}
        ALL
        COMMAND gdb -batch -ex 'file $<TARGET_FILE:${target}>' -ex 'disassemble ${function}' > ${target}_${function}.S
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS ${target}
        BYPRODUCTS ${CMAKE_CURRENT_BINARY_DIR}/${target}_${function}.S
        )
    set_target_properties(${name} PROPERTIES OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/${target}_${function}.S)
endfunction()
function(compare_asm target1 target2)
    get_target_property(asm1 ${target1} OUTPUT_FILE)
    get_target_property(asm2 ${target2} OUTPUT_FILE)
    add_test(NAME "cmp_${target1}_${target2}" COMMAND diff --side-by-side ${asm1} ${asm2})
endfunction()

function(ram_usage target)
    add_custom_target(ram_usage_${target}
        ALL
        COMMAND arm-none-eabi-size $<TARGET_FILE:${target}>
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS ${target}
        )
endfunction()


set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")

file(GLOB_RECURSE SYSTEM_SRC "Syscalls/*.c" "Startup/startup_stm32f746nghx.s")

# specify the cross compiler
SET(CMAKE_C_COMPILER arm-none-eabi-gcc)
SET(CMAKE_CXX_COMPILER arm-none-eabi-g++)
SET(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
SET(CMAKE_AR arm-none-eabi-ar CACHE PATH "" FORCE)
SET(CMAKE_RANLIB arm-none-eabi-ranlib CACHE PATH "" FORCE)
SET(CMAKE_LINKER arm-none-eabi-ld CACHE PATH "" FORCE)
SET(CMAKE_SIZE arm-none-eabi-size)
SET(CMAKE_OBJCOPY arm-none-eabi-objcopy)
SET(CMAKE_OBJDUMP arm-none-eabi-objdump)

SET(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/STM32F746NGHX_FLASH.ld)

SET(OPTIM_LEVEL "-O2")
SET(CPP_STANDARD "gnu++17")

SET(CMAKE_CXX_FLAGS "${OPTIM_LEVEL} -mcpu=cortex-m7 -flto -std=${CPP_STANDARD} -g3 -DSTM32 -DSTM32F746NGHx -DSTM32F746G_DISCO -DSTM32F7 -DDEBUG -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard")
SET(CMAKE_C_FLAGS "${OPTIM_LEVEL} -mcpu=cortex-m7 -flto -g3 -DSTM32 -DSTM32F746NGHx -DSTM32F746G_DISCO -DSTM32F7 -DDEBUG -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -std=gnu11" )
SET(CMAKE_ASM_FLAGS "-mcpu=cortex-m7 -flto -g3 -c -x assembler-with-cpp --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard " )
set (CMAKE_EXE_LINKER_FLAGS "-mcpu=cortex-m7 -flto -Wl,--gc-sections -mfpu=fpv5-sp-d16 -mfloat-abi=hard -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group -T ${LINKER_SCRIPT}" CACHE INTERNAL "executable linker flags")

file(GLOB_RECURSE SD_TESTS_SOURCES "Src/main.cpp")

add_executable(mp3_player ${SD_TESTS_SOURCES} ${SYSTEM_SRC} ${LINKER_SCRIPT})
ram_usage(mp3_player)
disassemble(mp3_player_asm mp3_player main)

add_executable(empty Src/empty.cpp ${SYSTEM_SRC} ${LINKER_SCRIPT})
ram_usage(empty)

add_executable(register_playground "Src/register_playground.cpp" ${SYSTEM_SRC} ${LINKER_SCRIPT})

add_executable(register_meta "Src/register_meta.cpp" ${SYSTEM_SRC} ${LINKER_SCRIPT})
add_executable(bitfield_meta "Src/bitfield_meta.cpp" ${SYSTEM_SRC} ${LINKER_SCRIPT})
add_executable(led_meta "Src/led_meta.cpp" ${SYSTEM_SRC} ${LINKER_SCRIPT})
add_executable(bitfield_or_meta "Src/bitfield_or_meta.cpp" ${SYSTEM_SRC} ${LINKER_SCRIPT})
ram_usage(bitfield_meta)

add_executable(register_c_like "Src/register_c_like.cpp" ${SYSTEM_SRC} ${LINKER_SCRIPT})
add_executable(led_c_like "Src/led_c_like.cpp" ${SYSTEM_SRC} ${LINKER_SCRIPT})
add_executable(bitfield_c_like "Src/bitfield_c_like.cpp" ${SYSTEM_SRC} ${LINKER_SCRIPT})

disassemble(register_c_like_asm register_c_like main)
disassemble(led_c_like_asm led_c_like main)
disassemble(bitfield_c_like_asm bitfield_c_like main)

disassemble(register_meta_asm register_meta main)
disassemble(bitfield_meta_asm bitfield_meta main)

enable_testing()

compare_asm(register_c_like_asm register_meta_asm)
compare_asm(bitfield_c_like_asm bitfield_meta_asm)

#set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)


