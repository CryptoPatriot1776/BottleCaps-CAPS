// Copyright (c) 2011-2014 The Bitcoin Core developers
// Copyright (c) 2017-2019 The Ravencoin Core developers
// Copyright (c) 2025 The Bottlecaps Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CAPS_QT_WALLETMODELTRANSACTION_H
#define CAPS_QT_WALLETMODELTRANSACTION_H

#include "walletmodel.h"

#include <QObject>

class SendCoinsRecipient;
class SendAssetsRecipient;

class CReserveKey;
class CWallet;
class CWalletTx;

/** Data model for a walletmodel transaction. */
class WalletModelTransaction
{
public:
    explicit WalletModelTransaction(const QList<SendCoinsRecipient> &recipients);
    ~WalletModelTransaction();

    QList<SendCoinsRecipient> getRecipients() const;

    CWalletTx *getTransaction() const;
    unsigned int getTransactionSize();

    void setTransactionFee(const CAmount& newFee);
    CAmount getTransactionFee() const;

    CAmount getTotalTransactionAmount() const;

    void newPossibleKeyChange(CWallet *wallet);
    CReserveKey *getPossibleKeyChange();

    void reassignAmounts(int nChangePosRet); // needed for the subtract-fee-from-amount feature

private:
    QList<SendCoinsRecipient> recipients;
    CWalletTx *walletTransaction;
    std::unique_ptr<CReserveKey> keyChange;
    CAmount fee;
};

#endif // CAPS_QT_WALLETMODELTRANSACTION_H
