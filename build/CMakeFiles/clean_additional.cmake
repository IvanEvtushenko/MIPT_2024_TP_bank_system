# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "BankSystem_TP_autogen"
  "CMakeFiles/BankSystem_TP_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/BankSystem_TP_autogen.dir/ParseCache.txt"
  )
endif()
