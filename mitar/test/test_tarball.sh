#!/bin/bash

FILES_TGT=/tmp/files
TARBALL_DIR=/tmp/my_tarball
TAR_FILE=$TARBALL_DIR/mytar.mtar

TF_0=$FILES_TGT/file0
TF_1=$FILES_TGT/file1

echo "Creating dir $FILES_TGT for test files"
mkdir -p $FILES_TGT

echo "Creating dir $TARBALL_DIR for test tarball"
mkdir -p $TARBALL_DIR

echo "Creating test file ${TF_0}"
cat << EOF > ${TF_0}
2 semanas,
3 semanas,
.. o 40.000 manianas
EOF

echo "Creating test file ${TF_1}"
cat << EOF > ${TF_1}
Oh oh oh, then they showed it to the world
Oh oh oh, every boy and girl
Don't tell anyone anything, keep it close to ya
Don't tell anyone anything, you never know, do ya?
EOF

echo "Files content"
cat ${TF_0} ${TF_1}

echo "Creating tarbal $TAR_FILE"

./mitar -c -f $TAR_FILE ${TF_0} ${TF_1}

echo "tar content"
cat $TAR_FILE

echo "removing test files"
rm -f ${TF_0} ${TF_1}

ls -la ${FILES_TGT}

echo "extracting files from tarball $TAR_FILE"
./mitar -x -f $TAR_FILE
ls -la ${FILES_TGT}
echo "Files content"
cat ${TF_0} ${TF_1}

