#pragma once

#include <string>
#include <sstream>
#include <algorithm>

#include "structureGeneration.hpp"
#include "Rectangle.hpp"

std::string genTable(const IterateStructure &structure)
{
    std::string result;
    std::stringstream ss;

    ss << "<table>\n";
    for (const auto &[_row, data] : structure)
    {
        ss << "<tr>\n";
        for (const auto &pair : data)
        {
            ss << "\t<td rowspan='" << pair.second.rowSpan << "' colspan='" << pair.second.colSpan << "'></td>\n";
        }
        ss << "</tr>\n";
    }
    ss << "</table>\n";
    return ss.str();
}

Dimensions getTableDimensions(const std::vector<Rectangle> &rectangles)
{
    int width = (*std::max_element(rectangles.begin(), rectangles.end(), [](const Rectangle &rect1, const Rectangle &rect2)
                                   { return rect1.bottomright.first < rect2.bottomright.first; }))
                    .bottomright.first;

    int height = (*std::max_element(rectangles.begin(), rectangles.end(), [](const Rectangle &rect1, const Rectangle &rect2)
                                    { return rect1.bottomright.second < rect2.bottomright.second; }))
                     .bottomright.second;

    return {width, height};
}