## mitar

Tarbal creator/extractor PoC

## Test

```
make test
```

## Usage example

> Create temp dir

```
mkdir /tmp/files
```

> Include some files


```
cat << EOF > /tmp/files/gd
Walk a lonely road..
the only one I've ever known
EOF
```

```
cat << EOF > /tmp/files/cs
You could have been a pretender
EOF
```

> Create tarball

```
./mitar -c -f myfiles.mytar /tmp/files/gd /tmp/files/cs
```

> Remove files

```
rm /tmp/files/*
```

> Extract files from tarball

```
./mitar -x -f myfiles.mytar
```

