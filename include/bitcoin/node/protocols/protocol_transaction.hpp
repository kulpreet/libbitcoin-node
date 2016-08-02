/**
 * Copyright (c) 2011-2015 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * libbitcoin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN_NODE_PROTOCOL_TRANSACTION_HPP
#define LIBBITCOIN_NODE_PROTOCOL_TRANSACTION_HPP

#include <memory>
#include <string>
#include <bitcoin/blockchain.hpp>
#include <bitcoin/network.hpp>
#include <bitcoin/node/define.hpp>

namespace libbitcoin {
namespace node {

class BCN_API protocol_transaction
  : public network::protocol_events, track<protocol_transaction>
{
public:
    typedef std::shared_ptr<protocol_transaction> ptr;

    /// Construct a transaction protocol instance.
    protocol_transaction(network::p2p& network, network::channel::ptr channel);

    /// Start the protocol.
    virtual void start();

private:

    // Sending.
    //-------------------------------------------------------------------------

    // requests
    ////void send_memory_pool(const code& ec);              // inventory->transations
    ////void send_get_data(const code& ec);                 // transaction

    // responses/notifications
    ////void send_inventory(const code& ec);                // memory_pool | announce
    ////void send_transaction(const hash_digest& hash);     // get_data->transaction

    // Receiving.
    //-------------------------------------------------------------------------

    ////// requests
    ////bool handle_receive_get_data(const code& ec, message::get_data::ptr message);

    ////// responses/notifications
    ////bool handle_receive_inventory(const code& ec, message::inventory::ptr message);
    ////bool handle_receive_transaction(const code& ec, message::transaction::ptr message);
    ////bool handle_receive_not_found(const code& ec, message::not_found::ptr message);

    // Other.
    //-------------------------------------------------------------------------
    ////void handle_store_transaction(const code& ec);
    ////void handle_transaction_pool(const code& ec, ...);
    void handle_send(const code& ec, const std::string& command);

    const bool relay_;
};

} // namespace node
} // namespace libbitcoin

#endif
