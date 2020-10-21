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

#ifndef _XML_GUARD
#define _XML_GUARD

#include <string>
#include <memory>
#include <iostream>
#include <vector>

namespace xml
{
    class tag
    {
    private:
        std::shared_ptr<std::string> _value;

    public:
        tag(const char *valor) : _value{std::make_shared<std::string>(valor)} {};
        tag(const std::string &valor) : _value{std::make_shared<std::string>(valor)} {};
        tag(const std::string &&valor) : _value{std::make_shared<std::string>(valor)} {};
        tag() : _value{std::make_shared<std::string>()} {};
        tag(const tag &t) : _value{t._value} {};
        tag(const tag &&t) : _value{t._value} {};

        virtual ~tag();

        std::string get() const;

        tag &operator=(const tag &t);
        tag &operator=(const char *valor);
        friend const tag operator<<(const tag &lref, const tag &rref);
        friend bool operator==(const tag &lref, const tag &rref);
        friend bool operator!=(const tag &lref, const tag &rref);
    };

} // namespace xml

#endif