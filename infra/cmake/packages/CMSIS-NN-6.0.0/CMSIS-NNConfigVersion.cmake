set(PACKAGE_VERSION "6.0.0")
set(PACKAGE_VERSION_EXACT FALSE)
set(PACKAGE_VERSION_COMPATIBLE FALSE)
set(PACKAGE_VERSION_UNSUITABLE TRUE)

if(PACKAGE_FIND_VERSION VERSION_EQUAL PACKAGE_VERSION)
    set(PACKAGE_VERSION_EXACT TRUE)
    set(PACKAGE_VERSION_COMPATIBLE TRUE)
    set(PACKAGE_VERSION_UNSUITABLE FALSE)
endif(PACKAGE_FIND_VERSION VERSION_EQUAL PACKAGE_VERSION)
