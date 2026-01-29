target("hello-mcpp")
    set_languages("c++23")
    add_files("hello-mcpp.cpp")
    add_files("../d2x/mcpp/common.cppm")

target("helloworld")
    add_files("helloworld.cpp")


