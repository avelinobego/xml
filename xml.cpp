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

#include "xml.hpp"

namespace xml
{
    tag::~tag()
    {
        this->_value.reset();
    }

    std::string tag::get() const
    {
        return std::string{*this->_value};
    }

    tag &tag::operator=(const tag &t)
    {
        if (*this != t)
        {
            this->_value = t._value;
        }
        return *this;
    }

    tag &tag::operator=(const char *valor)
    {
        this->_value->assign(valor);
        return *this;
    }

    const tag operator<<(const tag &lref, const tag &rref)
    {
        if (lref == rref)
        {
            return lref;
        }

        std::string value{*lref._value};
        value.append(*rref._value);

        tag temp{value};
        return temp;
    }

    bool operator==(const tag &lref, const tag &rref)
    {
        if (*lref._value == *rref._value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator!=(const tag &lref, const tag &rref)
    {
        if (*lref._value == *rref._value)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

} // namespace xml
