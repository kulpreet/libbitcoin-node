/**
 * Copyright (c) 2011-2015 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin-node.
 *
 * libbitcoin-node is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN_NODE_SETTINGS_TYPE_HPP
#define LIBBITCOIN_NODE_SETTINGS_TYPE_HPP

#include <cstdint>
#include <string>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <bitcoin/node/define.hpp>
#include <bitcoin/node/config/checkpoint.hpp>
#include <bitcoin/node/config/endpoint.hpp>
#include <bitcoin/node/config/settings.hpp>

namespace libbitcoin {
namespace node {
    
class BCN_API settings_type
{
public:
    settings_type()
    {
    }

    settings_type(const node::settings& node_settings,
        const chain::settings& chain_settings,
        const system::settings& system_settings)
      : node(node_settings), chain(chain_settings), system(system_settings)
    {
    }

    // settings
    node::settings node;
    chain::settings chain;
    system::settings system;

    // HACK: remove once logging is fully injected.
    std::string skip_log;
};

} // namespace node
} // namespace libbitcoin

#endif
