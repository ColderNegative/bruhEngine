package(default_visibility = ["//visibility:public"])

cc_library(
    name = "glad",
    hdrs = ["glad.h"],
    srcs = ["glad.c"],
    deps = [":khrplatform"],
    linkopts = ["-DEFAULTLIB:opengl32.lib"],
    linkstatic = False,
)

cc_library(
    name = "khrplatform",
    hdrs = ["khrplatform.h"],
)