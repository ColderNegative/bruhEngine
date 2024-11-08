package(default_visibility = ["//visibility:public"])

cc_library(
    name = "input",
    hdrs = ["input.hpp"],
    srcs = ["input.cpp"],
    deps = ["//src/templates:singleton", "//lib:glfw", "//src/render:window", "//include:glad", "//include:khrplatform"],
    linkstatic = False,
)

cc_library(
    name = "resource",
    hdrs = ["resource.hpp"],
    srcs = ["resource.cpp"],
    deps = ["//src/templates:singleton"],
)