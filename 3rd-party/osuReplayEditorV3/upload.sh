#!/bin/sh

WHICH_DIR=~/Desktop/editor_upload
rm -rf $WHICH_DIR

if [ -z "$2" ]; then
	echo 'Usage:' $0 ' {github_username} {ssh_config}'
	echo ' - OR -'
	echo 'Usage:' $0 ' clean'
	exit 1
fi

cp -R distro $WHICH_DIR
cp -r distro_aux/. $WHICH_DIR
cd $WHICH_DIR
git init
git config user.name $1
git config user.email $1'@users.noreply.github.com'
git remote add origin $2':'$1'/osuReplayEditorV3.git'
git add --all
git commit -m "`date '+%Y-%m-%d [%y%j-%H]'`"
git tag beta
git push -uf origin master
git push -f origin beta
rm -rf $WHICH_DIR
