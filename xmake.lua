set_encodings("source:utf-8", "target:utf-8")
set_languages("c++23")

add_includedirs(".")

-- 设置自定义插件目录
add_plugindirs("d2x/buildtools")

option("lang")
    set_default("zh")
    set_description("Language: zh or en")

local lang = get_config("lang")

if lang == "en" then
    includes("dslings/en/xmake.lua")
else
    includes("dslings/xmake.lua")
end