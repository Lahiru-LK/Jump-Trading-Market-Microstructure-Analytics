/**
 *
 * Market data updates are batched to fill "packets"
 *
 * A packet will always start with a PacketHeader indicating the size of the packet and the packet sequence number.
 * Following the header are a series of Market Data updates.  A packet may contain 1+ MD updates.
 * All packets will contain at least one update, and updates will not span across multiple packets.
 *
 * Updates will always be one of the following types: AddOrder, ModifyOrder, CancelOrder, TradeOrder
 *
 *
 */

#pragma once

// Maximum packet size
const int PACKET_MTU=1500;

typedef int32_t OrderId_t;
typedef int32_t Price_t;
typedef uint64_t Timestamp_t;

struct PacketHeader {
  // The total size of the packet, inclusive of this field.
  // Example, if the payload is size 12 bytes, packetSizeInclusive will be 12 + sizeOf(seqNum) + sizeOf(packetSizeInclusive).
  uint16_t packetSizeInclusive;
  uint16_t seqNum;
}__attribute__((packed));

struct BaseUpdate {
  uint8_t updateType;
  Timestamp_t exchangePublishTimestamp;
  Timestamp_t exchangeReceiptTimestamp;
}__attribute__((packed));

enum class UpdateType : decltype(BaseUpdate::updateType) {
  AddOrder = 1,
  CancelOrder = 2,
  ModifyOrder = 3,
  TradeOrder = 4,
};

struct OrderBookUpdate  {
  Price_t bestAskPrice;
  Price_t bestBidPrice;
  uint32_t bestAskQty;
  uint32_t bestBidQty;
  uint16_t bestAskNumOrders;
  uint16_t bestBidNumOrders;

}__attribute__((packed));

struct OrderDetailUpdate {
  OrderId_t orderId;
  Price_t price;
  uint16_t quantity;
  uint16_t traderId;
  int8_t symbol;
  uint8_t isBuy;
}__attribute__((packed));

struct AddOrder {
  BaseUpdate base;
  OrderBookUpdate book;
  OrderDetailUpdate order;
}__attribute__((packed));

struct ModifyOrder  {
  BaseUpdate base;
  OrderBookUpdate book;
  OrderDetailUpdate order;
}__attribute__((packed));

struct CancelOrder  {
  BaseUpdate base;
  OrderBookUpdate book;
  OrderId_t orderId;
}__attribute__((packed));

struct TradeOrder  {
  BaseUpdate base;
  OrderBookUpdate book;
  OrderDetailUpdate order;
  uint8_t isAggressor;
}__attribute__((packed));
