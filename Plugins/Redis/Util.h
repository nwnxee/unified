#pragma once

#include <string>
#include <vector>

std::string str_implode(const std::vector<std::string>& v,
                        const std::string delim = " ");


std::vector<std::string> str_explode(const std::string& sp,
                                     char delim);
