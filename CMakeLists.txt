# CMakeList.txt : CMake project for ComputePipeline, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("ComputePipeline")

# Add source to this project's executable.
add_executable (ComputePipeline "ComputePipeline.cpp"
								"ComputePipeline.h"
								"Public/Actions/Action.h"
								"Public/DataObject.h"
								"Public/MetaData.h"
								"Public/Pipeline.h"
								"Public/Utility.h"
								"Public/Actions/LoadFileAction.h"
								"Public/Actions/ExtractZipAction.h"
								"Public/Actions/ImgDecodeAction.h"
								"Public/Actions/JSONParseAction.h"
								"Private/Pipeline.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ComputePipeline PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
