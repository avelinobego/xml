//--------------------------------------------------------------------------------------
// Copyright (C) 2020  Avelino de Almeida Bego <avelino.bego@gmail.com>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//--------------------------------------------------------------------------------------

#include <iostream>
#include "xml.hpp"
#define BOOST_TEST_MODULE tagmodule
#include <boost/test/included/unit_test.hpp>
#include <stdexcept>

bool teste_igualdade()
{
    xml::tag TAG = "<html>";
    xml::tag TAG2 = "<html>";

    return TAG == TAG2;
}

bool teste_diferente()
{
    xml::tag TAG = "<html>";
    xml::tag TAG2 = "</html>";

    return TAG != TAG2;
}

BOOST_AUTO_TEST_CASE(xml_tag)
{
    BOOST_TEST(teste_igualdade);
    BOOST_TEST(teste_diferente);
}