set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)
project(fatpp C CXX ASM)
cmake_minimum_required(VERSION 3.5.0)

set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")

file(GLOB_RECURSE USER_SOURCES "Src/*.c" "Src/*.cpp" "Startup/startup_stm32f746nghx.s")

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

SET(OPTIM_LEVEL "-O0")

SET(CMAKE_CXX_FLAGS "${OPTIM_LEVEL} -mcpu=cortex-m7 -std=gnu++17 -g3 -DSTM32 -DSTM32F746NGHx -DSTM32F746G_DISCO -DSTM32F7 -DDEBUG -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard")
SET(CMAKE_C_FLAGS "${OPTIM_LEVEL} -mcpu=cortex-m7 -g3 -DSTM32 -DSTM32F746NGHx -DSTM32F746G_DISCO -DSTM32F7 -DDEBUG -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -std=gnu11" )
SET(CMAKE_ASM_FLAGS "-mcpu=cortex-m7 -g3 -c -x assembler-with-cpp --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard " )
set (CMAKE_EXE_LINKER_FLAGS "-mcpu=cortex-m7 -Wl,--gc-sections -mfpu=fpv5-sp-d16 -mfloat-abi=hard -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group -T ${LINKER_SCRIPT}" CACHE INTERNAL "executable linker flags")



add_executable(${PROJECT_NAME} ${USER_SOURCES} ${LINKER_SCRIPT})
#set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

