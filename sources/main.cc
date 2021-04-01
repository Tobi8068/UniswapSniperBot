#include <utils.hpp>
#include <transaction.hpp>
#include <bloxroute.hpp>

using namespace Utils;
using BloXroute::BloXrouteBot;

int main() {
  BloXroute::ConnectionConfig bloxrouteConnectionConfig {
    .address = "wss://8.208.24.157/ws",
    .authorizationToken = "<auth_token>"
  };

  BloXroute::ListenerFilters bloxrouteListenerFilters {
    .targetTokenAddress = "48bef6bd05bd23b5e6800cf0406e524b517af250",
    .maximumGasPrice = "500000000000",
    .minimumLiquidityETH = "5000000000000000000",
  };

  BloXroute::TransactionInputData bloxrouteTransactionInputData {
    .amountOutMin = "3635c9adc5dea00000",
    .receiverAddress = "f82d59152f33e6f65aa4ae1a3b38ed2ca1b7633b",
    .targetTokenAddress = "48bef6bd05bd23b5e6800cf0406e524b517af250"
  };

  Transaction::ETHValues transactionValues {
    .nonce = "1",
    .gasLimit = "30d40",
    .to = "7a250d5630B4cF539739dF2C5dAcb4c659F2488D",
    .value = "de0b6b3a7640000"
  };

  BloXroute::TransactionConfig bloxrouteTransactionConfig {
    .transactionInputData = &bloxrouteTransactionInputData,
    .transactionValues = &transactionValues
  };

  hexStringToBuffer("<private_key>", bloxrouteTransactionConfig.privateKey);

  BloXrouteBot bloxrouteBot { &bloxrouteConnectionConfig, &bloxrouteListenerFilters, &bloxrouteTransactionConfig };
  bloxrouteBot.run();
}