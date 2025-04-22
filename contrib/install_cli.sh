 #!/usr/bin/env bash

 # Execute this file to install the caps cli tools into your path on OS X

 CURRENT_LOC="$( cd "$(dirname "$0")" ; pwd -P )"
 LOCATION=${CURRENT_LOC%Caps-Qt.app*}

 # Ensure that the directory to symlink to exists
 sudo mkdir -p /usr/local/bin

 # Create symlinks to the cli tools
 sudo ln -s ${LOCATION}/Caps-Qt.app/Contents/MacOS/capsd /usr/local/bin/capsd
 sudo ln -s ${LOCATION}/Caps-Qt.app/Contents/MacOS/caps-cli /usr/local/bin/caps-cli
