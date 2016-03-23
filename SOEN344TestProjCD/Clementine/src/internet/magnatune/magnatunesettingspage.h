/* This file is part of Clementine.
   Copyright 2010-2011, David Sansome <me@davidsansome.com>
   Copyright 2011, 2014, John Maguire <john.maguire@gmail.com>
   Copyright 2014, Krzysztof Sobiecki <sobkas@gmail.com>

   Clementine is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Clementine is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Clementine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef INTERNET_MAGNATUNE_MAGNATUNESETTINGSPAGE_H_
#define INTERNET_MAGNATUNE_MAGNATUNESETTINGSPAGE_H_

#include "ui/settingspage.h"

class QAuthenticator;
class QNetworkReply;

class NetworkAccessManager;
class Ui_MagnatuneSettingsPage;

class MagnatuneSettingsPage : public SettingsPage {
  Q_OBJECT
 public:
  explicit MagnatuneSettingsPage(SettingsDialog* dialog);
  ~MagnatuneSettingsPage();

  void Load();
  void Save();

 private slots:
  void Login();
  void Logout();
  void MembershipChanged(int value);
  void LoginFinished();
  void AuthenticationRequired(QNetworkReply* reply, QAuthenticator* auth);

 private:
  void UpdateLoginState();

 private:
  NetworkAccessManager* network_;
  Ui_MagnatuneSettingsPage* ui_;

  bool logged_in_;
};

#endif  // INTERNET_MAGNATUNE_MAGNATUNESETTINGSPAGE_H_
