set( LIBRARY_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/Logger.cpp"
)
set( LIBRARY_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/Logger.h"
)
set( LIBRARY_INCLUDES
    "./"
    "${CMAKE_BINARY_DIR}/configured_files/include"
)

if(BUILD_STATIC_LIBRARY)
    add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
else()
    add_library(${LIBRARY_NAME} SHARED ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
endif()
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_INCLUDES})


if(ENABLE_WARNINGS)
    target_set_warnings(
        TARGET
        ${LIBRARY_NAME}
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS}
    )

endif()

if(ENABLE_LTO)
    target_enable_lto(
        TARGET
        ${LIBRARY_NAME}
        ENABLE
        ON
    )
endif()