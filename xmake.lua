set_project("mastl")
set_version("0.0.1")

if is_mode("release") then
  set_optimize("faster")
  set_strip("all")
elseif is_mode("debug") then
  set_symbols("debug")
  set_optimize("none")
end

set_languages("c++17")
set_warnings("all")
set_exceptions("no-cxx")

set_config("buildir", "build.xmake")
-- add_cflags("-fPIC", "-pipe")
includes("test", "utils")
