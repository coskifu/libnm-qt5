/*
    Copyright 2012-2013  Jan Grulich <jgrulich@redhat.com>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) version 3, or any
    later version accepted by the membership of KDE e.V. (or its
    successor approved by the membership of KDE e.V.), which shall
    act as a proxy defined in Section 6 of version 3 of the license.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "wirelesssecuritysetting.h"
#include "wirelesssecuritysetting_p.h"

#include <nm-setting-wireless-security.h>

#include <QtCore/QDebug>

NetworkManager::Settings::WirelessSecuritySettingPrivate::WirelessSecuritySettingPrivate():
    name(NM_SETTING_WIRELESS_SECURITY_SETTING_NAME),
    keyMgmt(NetworkManager::Settings::WirelessSecuritySetting::Unknown),
    wepTxKeyidx(0),
    authAlg(NetworkManager::Settings::WirelessSecuritySetting::None),
    wepKeyFlags(NetworkManager::Settings::Setting::None),
    wepKeyType(NetworkManager::Settings::WirelessSecuritySetting::NotSpecified),
    pskFlags(NetworkManager::Settings::Setting::None),
    leapPasswordFlags(NetworkManager::Settings::Setting::None)
{ }

NetworkManager::Settings::WirelessSecuritySetting::WirelessSecuritySetting():
    Setting(Setting::WirelessSecurity),
    d_ptr(new WirelessSecuritySettingPrivate())
{ }

NetworkManager::Settings::WirelessSecuritySetting::WirelessSecuritySetting(const Ptr &other):
    Setting(Setting::WirelessSecurity),
    d_ptr(new WirelessSecuritySettingPrivate())
{
    setKeyMgmt(other->keyMgmt());
    setWepTxKeyindex(other->wepTxKeyindex());
    setAuthAlg(other->authAlg());
    setProto(other->proto());
    setPairwise(other->pairwise());
    setGroup(other->group());
    setWepKey0(other->wepKey0());
    setWepKey1(other->wepKey1());
    setWepKey2(other->wepKey2());
    setWepKey3(other->wepKey3());
    setWepKeyFlags(other->wepKeyFlags());
    setWepKeyType(other->wepKeyType());
    setPsk(other->psk());
    setPskFlags(other->pskFlags());
    setLeapPassword(other->leapPassword());
    setLeapPasswordFlags(other->leapPasswordFlags());
}

NetworkManager::Settings::WirelessSecuritySetting::~WirelessSecuritySetting()
{
    delete d_ptr;
}

QString NetworkManager::Settings::WirelessSecuritySetting::name() const
{
    Q_D(const WirelessSecuritySetting);

    return d->name;
}

void NetworkManager::Settings::WirelessSecuritySetting::setKeyMgmt(NetworkManager::Settings::WirelessSecuritySetting::KeyMgmt mgmt)
{
    Q_D(WirelessSecuritySetting);

    d->keyMgmt = mgmt;
}

NetworkManager::Settings::WirelessSecuritySetting::KeyMgmt NetworkManager::Settings::WirelessSecuritySetting::keyMgmt() const
{
    Q_D(const WirelessSecuritySetting);

    return d->keyMgmt;
}

void NetworkManager::Settings::WirelessSecuritySetting::setWepTxKeyindex(quint32 index)
{
    Q_D(WirelessSecuritySetting);

    d->wepTxKeyidx = index;
}

quint32 NetworkManager::Settings::WirelessSecuritySetting::wepTxKeyindex() const
{
    Q_D(const WirelessSecuritySetting);

    return d->wepTxKeyidx;
}

void NetworkManager::Settings::WirelessSecuritySetting::setAuthAlg(NetworkManager::Settings::WirelessSecuritySetting::AuthAlg alg)
{
    Q_D(WirelessSecuritySetting);

    d->authAlg = alg;
}

NetworkManager::Settings::WirelessSecuritySetting::AuthAlg NetworkManager::Settings::WirelessSecuritySetting::authAlg() const
{
    Q_D(const WirelessSecuritySetting);

    return d->authAlg;
}

void NetworkManager::Settings::WirelessSecuritySetting::setProto(const QList< NetworkManager::Settings::WirelessSecuritySetting::WpaProtocolVersion >& list)
{
    Q_D(WirelessSecuritySetting);

    d->proto = list;
}

QList< NetworkManager::Settings::WirelessSecuritySetting::WpaProtocolVersion > NetworkManager::Settings::WirelessSecuritySetting::proto() const
{
    Q_D(const WirelessSecuritySetting);

    return d->proto;
}

void NetworkManager::Settings::WirelessSecuritySetting::setPairwise(const QList< NetworkManager::Settings::WirelessSecuritySetting::WpaEncryptionCapabilities >& list)
{
    Q_D(WirelessSecuritySetting);

    d->pairwise = list;
}

QList< NetworkManager::Settings::WirelessSecuritySetting::WpaEncryptionCapabilities > NetworkManager::Settings::WirelessSecuritySetting::pairwise() const
{
    Q_D(const WirelessSecuritySetting);

    return d->pairwise;
}

void NetworkManager::Settings::WirelessSecuritySetting::setGroup(const QList< NetworkManager::Settings::WirelessSecuritySetting::WpaEncryptionCapabilities >& list)
{
    Q_D(WirelessSecuritySetting);

    d->group = list;
}

QList< NetworkManager::Settings::WirelessSecuritySetting::WpaEncryptionCapabilities > NetworkManager::Settings::WirelessSecuritySetting::group() const
{
    Q_D(const WirelessSecuritySetting);

    return d->group;
}

void NetworkManager::Settings::WirelessSecuritySetting::setLeapUsername(const QString& username)
{
    Q_D(WirelessSecuritySetting);

    d->leapUsername = username;
}

QString NetworkManager::Settings::WirelessSecuritySetting::leapUsername() const
{
    Q_D(const WirelessSecuritySetting);

    return d->leapUsername;
}

void NetworkManager::Settings::WirelessSecuritySetting::setWepKey0(const QString key)
{
    Q_D(WirelessSecuritySetting);

    d->wepKey0 = key;
}

QString NetworkManager::Settings::WirelessSecuritySetting::wepKey0() const
{
    Q_D(const WirelessSecuritySetting);

    return d->wepKey0;
}

void NetworkManager::Settings::WirelessSecuritySetting::setWepKey1(const QString key)
{
    Q_D(WirelessSecuritySetting);

    d->wepKey1 = key;
}

QString NetworkManager::Settings::WirelessSecuritySetting::wepKey1() const
{
    Q_D(const WirelessSecuritySetting);

    return d->wepKey1;
}

void NetworkManager::Settings::WirelessSecuritySetting::setWepKey2(const QString key)
{
    Q_D(WirelessSecuritySetting);

    d->wepKey2 = key;
}

QString NetworkManager::Settings::WirelessSecuritySetting::wepKey2() const
{
    Q_D(const WirelessSecuritySetting);

    return d->wepKey2;
}

void NetworkManager::Settings::WirelessSecuritySetting::setWepKey3(const QString key)
{
    Q_D(WirelessSecuritySetting);

    d->wepKey3 = key;
}

QString NetworkManager::Settings::WirelessSecuritySetting::wepKey3() const
{
    Q_D(const WirelessSecuritySetting);

    return d->wepKey3;
}

void NetworkManager::Settings::WirelessSecuritySetting::setWepKeyFlags(NetworkManager::Settings::Setting::SecretFlags type)
{
    Q_D(WirelessSecuritySetting);

    d->wepKeyFlags = type;
}

NetworkManager::Settings::Setting::SecretFlags NetworkManager::Settings::WirelessSecuritySetting::wepKeyFlags() const
{
    Q_D(const WirelessSecuritySetting);

    return d->wepKeyFlags;
}

void NetworkManager::Settings::WirelessSecuritySetting::setWepKeyType(NetworkManager::Settings::WirelessSecuritySetting::WepKeyType type)
{
    Q_D(WirelessSecuritySetting);

    d->wepKeyType = type;
}

NetworkManager::Settings::WirelessSecuritySetting::WepKeyType NetworkManager::Settings::WirelessSecuritySetting::wepKeyType() const
{
    Q_D(const WirelessSecuritySetting);

    return d->wepKeyType;
}

void NetworkManager::Settings::WirelessSecuritySetting::setPsk(const QString& key)
{
    Q_D(WirelessSecuritySetting);

    d->psk = key;
}

QString NetworkManager::Settings::WirelessSecuritySetting::psk() const
{
    Q_D(const WirelessSecuritySetting);

    return d->psk;
}

void NetworkManager::Settings::WirelessSecuritySetting::setPskFlags(NetworkManager::Settings::Setting::SecretFlags type)
{
    Q_D(WirelessSecuritySetting);

    d->pskFlags = type;
}

NetworkManager::Settings::Setting::SecretFlags NetworkManager::Settings::WirelessSecuritySetting::pskFlags() const
{
    Q_D(const WirelessSecuritySetting);

    return d->pskFlags;
}

void NetworkManager::Settings::WirelessSecuritySetting::setLeapPassword(const QString& password)
{
    Q_D(WirelessSecuritySetting);

    d->leapPassword = password;
}

QString NetworkManager::Settings::WirelessSecuritySetting::leapPassword() const
{
    Q_D(const WirelessSecuritySetting);

    return d->leapPassword;
}

void NetworkManager::Settings::WirelessSecuritySetting::setLeapPasswordFlags(NetworkManager::Settings::Setting::SecretFlags type)
{
    Q_D(WirelessSecuritySetting);

    d->leapPasswordFlags = type;
}

NetworkManager::Settings::Setting::SecretFlags NetworkManager::Settings::WirelessSecuritySetting::leapPasswordFlags() const
{
    Q_D(const WirelessSecuritySetting);

    return d->leapPasswordFlags;
}

void NetworkManager::Settings::WirelessSecuritySetting::secretsFromMap(const QVariantMap& secrets)
{
    if (secrets.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY0))) {
        setWepKey0(secrets.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY0)).toString());
    }

    if (secrets.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY1))) {
        setWepKey1(secrets.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY1)).toString());
    }

    if (secrets.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY2))) {
        setWepKey2(secrets.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY2)).toString());
    }

    if (secrets.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY3))) {
        setWepKey3(secrets.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY3)).toString());
    }

    if (secrets.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_PSK))) {
        setPsk(secrets.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_PSK)).toString());
    }

    if (secrets.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_LEAP_PASSWORD))) {
        setLeapPassword(secrets.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_LEAP_PASSWORD)).toString());
    }
}

QVariantMap NetworkManager::Settings::WirelessSecuritySetting::secretsToMap() const
{
    QVariantMap secrets;

    if (!wepKey0().isEmpty()) {
        secrets.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY0), wepKey0());
    }

    if (!wepKey1().isEmpty()) {
        secrets.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY1), wepKey1());
    }

    if (!wepKey2().isEmpty()) {
        secrets.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY2), wepKey2());
    }

    if (!wepKey3().isEmpty()) {
        secrets.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY3), wepKey3());
    }

    if (!psk().isEmpty()) {
        secrets.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_PSK), psk());
    }

    if (!leapPassword().isEmpty()) {
        secrets.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_LEAP_PASSWORD), leapPassword());
    }

    return secrets;
}

QStringList NetworkManager::Settings::WirelessSecuritySetting::needSecrets(bool requestNew) const
{
    QStringList secrets;

    if (keyMgmt() == Wep) {
        if (!wepKeyFlags().testFlag(Setting::NotRequired)) {
            switch (wepTxKeyindex()) {
            case 0:
                if (wepKey0().isEmpty() || requestNew) {
                    secrets << QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY0);
                    return secrets;
                }
                break;
            case 1:
                if (wepKey1().isEmpty() || requestNew) {
                    secrets << QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY1);
                    return secrets;
                }
                break;
            case 2:
                if (wepKey2().isEmpty() || requestNew) {
                    secrets << QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY2);
                    return secrets;
                }
                break;
            case 3:
                if (wepKey3().isEmpty() || requestNew) {
                    secrets << QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY3);
                    return secrets;
                }
                break;
            }
        }
    }

    if (keyMgmt() == WpaNone ||
            keyMgmt() == WpaPsk) {
        if (!pskFlags().testFlag(Setting::NotRequired)) {
            if (psk().isEmpty() || requestNew) {
                secrets << QLatin1String(NM_SETTING_WIRELESS_SECURITY_PSK);
                return secrets;
            }
        }
    }

    if (authAlg() == Leap &&
            keyMgmt() == Ieee8021x) {
        if (!leapPasswordFlags().testFlag(Setting::NotRequired)) {
            if (leapPassword().isEmpty() || requestNew) {
                secrets << QLatin1String(NM_SETTING_WIRELESS_SECURITY_LEAP_PASSWORD);
                return secrets;
            }
        }
    }

    return secrets;
}

void NetworkManager::Settings::WirelessSecuritySetting::fromMap(const QVariantMap& map)
{
    if (map.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_KEY_MGMT))) {
        QString key = map.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_KEY_MGMT)).toString();
        if (key == "none") {
            setKeyMgmt(Wep);
        } else if (key == "ieee8021x") {
            setKeyMgmt(Ieee8021x);
        } else if (key == "wpa-none") {
            setKeyMgmt(WpaNone);
        } else if (key == "wpa-psk") {
            setKeyMgmt(WpaPsk);
        } else if (key == "wpa-eap") {
            setKeyMgmt(WpaEap);
        }
    }

    if (map.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_TX_KEYIDX))) {
        setWepTxKeyindex(map.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_TX_KEYIDX)).toUInt());
    }

    if (map.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_AUTH_ALG))) {
        QString alg = map.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_AUTH_ALG)).toString();
        if (alg == "open") {
            setAuthAlg(Open);
        } else if (alg == "shared") {
            setAuthAlg(Shared);
        } else if (alg == "leap") {
            setAuthAlg(Leap);
        }
    }

    if (map.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_PROTO))) {
        QStringList strList = map.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_PROTO)).toStringList();
        QList<WpaProtocolVersion> list;
        foreach(const QString & str, strList) {
            if (str == "wpa") {
                list.push_back(Wpa);
            } else if (str == "rsn") {
                list.push_back(Rsn);
            }
        }
        setProto(list);
    }

    if (map.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_PAIRWISE))) {
        QStringList strList = map.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_PAIRWISE)).toStringList();
        QList<WpaEncryptionCapabilities> list;
        foreach(const QString & str, strList) {
            if (str == "wep40") {
                list.push_back(Wep40);
            } else if (str == "wep104") {
                list.push_back(Wep104);
            } else if (str == "tkip") {
                list.push_back(Tkip);
            } else if (str == "ccmp") {
                list.push_back(Ccmp);
            }
        }
        setPairwise(list);
    }

    if (map.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_GROUP))) {
        QStringList strList = map.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_GROUP)).toStringList();
        QList<WpaEncryptionCapabilities> list;
        foreach(const QString & str, strList) {
            if (str == "wep40") {
                list.push_back(Wep40);
            } else if (str == "wep104") {
                list.push_back(Wep104);
            } else if (str == "tkip") {
                list.push_back(Tkip);
            } else if (str == "ccmp") {
                list.push_back(Ccmp);
            }
        }
        setGroup(list);
    }

    if (map.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_LEAP_USERNAME))) {
        setLeapUsername(map.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_LEAP_USERNAME)).toString());
    }

    // Secrets
    if (map.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY0))) {
        setWepKey0(map.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY0)).toString());
    }

    // Secrets
    if (map.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY1))) {
        setWepKey1(map.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY1)).toString());
    }

    // Secrets
    if (map.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY2))) {
        setWepKey2(map.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY2)).toString());
    }

    // Secrets
    if (map.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY3))) {
        setWepKey3(map.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY3)).toString());
    }

    if (map.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY_FLAGS))) {
        setWepKeyFlags((SecretFlags)map.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY_FLAGS)).toInt());
    }

    if (map.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY_TYPE))) {
        setWepKeyType((WepKeyType)map.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY_TYPE)).toUInt());
    }

    // Secrets
    if (map.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_PSK))) {
        setPsk(map.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_PSK)).toString());
    }

    if (map.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_PSK_FLAGS))) {
        setPskFlags((SecretFlags)map.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_PSK_FLAGS)).toInt());
    }

    // Secrets
    if (map.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_LEAP_PASSWORD))) {
        setLeapPassword(map.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_LEAP_PASSWORD)).toString());
    }

    if (map.contains(QLatin1String(NM_SETTING_WIRELESS_SECURITY_LEAP_PASSWORD_FLAGS))) {
        setLeapPasswordFlags((SecretFlags)map.value(QLatin1String(NM_SETTING_WIRELESS_SECURITY_LEAP_PASSWORD_FLAGS)).toInt());
    }
}

QVariantMap NetworkManager::Settings::WirelessSecuritySetting::toMap() const
{
    QVariantMap setting;

    if (keyMgmt() == Wep) {
        setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_KEY_MGMT), "none");
    } else if (keyMgmt() == Ieee8021x) {
        setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_KEY_MGMT), "ieee8021x");
    } else if (keyMgmt() == WpaNone) {
        setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_KEY_MGMT), "wpa-none");
    } else if (keyMgmt() == WpaPsk) {
        setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_KEY_MGMT), "wpa-psk");
    } else if (keyMgmt() == WpaEap) {
        setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_KEY_MGMT), "wpa-eap");
    }

    if (wepTxKeyindex()) {
        setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_TX_KEYIDX), wepTxKeyindex());
    }

    if (authAlg() != None) {
        if (authAlg() == Open) {
            setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_AUTH_ALG), "open");
        } else if (authAlg() == Shared) {
            setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_AUTH_ALG), "shared");
        } else if (authAlg() == Leap) {
            setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_AUTH_ALG), "leap");
        }
    }

    if (!proto().isEmpty()) {
        QStringList strList;
        foreach(WpaProtocolVersion version, proto()) {
            if (version == Wpa) {
                strList << "wpa";
            } else if (version == Rsn) {
                strList << "rsn";
            }
        }
        setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_PROTO), strList);
    }

    if (!pairwise().isEmpty()) {
        QStringList strList;
        foreach(WpaEncryptionCapabilities capability, pairwise()) {
            if (capability == Wep40) {
                strList << "wep40";
            } else if (capability == Wep104) {
                strList << "wep104";
            } else if (capability == Tkip) {
                strList << "tkip";
            } else if (capability == Ccmp) {
                strList << "ccmp";
            }
        }
        setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_PAIRWISE), strList);
    }

    if (!group().isEmpty()) {
        QStringList strList;
        foreach(WpaEncryptionCapabilities capability, group()) {
            if (capability == Wep40) {
                strList << "wep40";
            } else if (capability == Wep104) {
                strList << "wep104";
            } else if (capability == Tkip) {
                strList << "tkip";
            } else if (capability == Ccmp) {
                strList << "ccmp";
            }
        }
        setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_GROUP), strList);
    }

    if (!leapUsername().isEmpty()) {
        setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_LEAP_USERNAME), leapUsername());
    }

    // Secrets
    if (!wepKey0().isEmpty()) {
        setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY0), wepKey0());
    }

    // Secrets
    if (!wepKey1().isEmpty()) {
        setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY1), wepKey1());
    }

    // Secrets
    if (!wepKey2().isEmpty()) {
        setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY2), wepKey2());
    }

    // Secrets
    if (!wepKey3().isEmpty()) {
        setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY3), wepKey3());
    }

    if (wepKeyFlags()) {
        setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY_FLAGS), (int)wepKeyFlags());
    }

    if (wepKeyType()) {
        setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_WEP_KEY_TYPE), wepKeyType());
    }

    // Secrets
    if (!psk().isEmpty()) {
        setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_PSK), psk());
    }

    if (pskFlags()) {
        setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_PSK_FLAGS), (int)pskFlags());
    }

    // Secrets
    if (!leapPassword().isEmpty()) {
        setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_LEAP_PASSWORD), leapPassword());
    }

    if (leapPasswordFlags()) {
        setting.insert(QLatin1String(NM_SETTING_WIRELESS_SECURITY_LEAP_PASSWORD_FLAGS), (int)leapPasswordFlags());
    }

    return setting;
}

QDebug NetworkManager::Settings::operator <<(QDebug dbg, const NetworkManager::Settings::WirelessSecuritySetting &setting)
{
    dbg.nospace() << static_cast<NetworkManager::Settings::Setting>(setting);

    dbg.nospace() << NM_SETTING_WIRELESS_SECURITY_KEY_MGMT << ": " << setting.keyMgmt() << '\n';
    dbg.nospace() << NM_SETTING_WIRELESS_SECURITY_WEP_TX_KEYIDX << ": " << setting.wepTxKeyindex() << '\n';
    dbg.nospace() << NM_SETTING_WIRELESS_SECURITY_AUTH_ALG << ": " << setting.authAlg() << '\n';
    dbg.nospace() << NM_SETTING_WIRELESS_SECURITY_PROTO << ": " << setting.proto() << '\n';
    dbg.nospace() << NM_SETTING_WIRELESS_SECURITY_PAIRWISE << ": " << setting.pairwise() << '\n';
    dbg.nospace() << NM_SETTING_WIRELESS_SECURITY_GROUP << ": " << setting.group() << '\n';
    dbg.nospace() << NM_SETTING_WIRELESS_SECURITY_LEAP_USERNAME << ": " << setting.leapUsername() << '\n';
    dbg.nospace() << NM_SETTING_WIRELESS_SECURITY_WEP_KEY0 << ": " << setting.wepKey0() << '\n';
    dbg.nospace() << NM_SETTING_WIRELESS_SECURITY_WEP_KEY1 << ": " << setting.wepKey1() << '\n';
    dbg.nospace() << NM_SETTING_WIRELESS_SECURITY_WEP_KEY2 << ": " << setting.wepKey2() << '\n';
    dbg.nospace() << NM_SETTING_WIRELESS_SECURITY_WEP_KEY3 << ": " << setting.wepKey3() << '\n';
    dbg.nospace() << NM_SETTING_WIRELESS_SECURITY_WEP_KEY_FLAGS << ": " << setting.wepKeyFlags() << '\n';
    dbg.nospace() << NM_SETTING_WIRELESS_SECURITY_WEP_KEY_TYPE << ": " << setting.wepKeyType() << '\n';
    dbg.nospace() << NM_SETTING_WIRELESS_SECURITY_PSK << ": " << setting.psk() << '\n';
    dbg.nospace() << NM_SETTING_WIRELESS_SECURITY_PSK_FLAGS << ": " << setting.pskFlags() << '\n';
    dbg.nospace() << NM_SETTING_WIRELESS_SECURITY_LEAP_PASSWORD << ": " << setting.leapPassword() << '\n';
    dbg.nospace() << NM_SETTING_WIRELESS_SECURITY_LEAP_PASSWORD_FLAGS << ": " << setting.leapPasswordFlags() << '\n';

    return dbg.maybeSpace();
}