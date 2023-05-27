# raia-app

## SteamDeck

```shell
sudo steamos-readonl disable
sudo pacman-key --init
sudo pacman-key --populate archlinux
# sudo pacman -S bc
# sudo pacman -S --overwrite
sudo pacman -S linux-neptune-headers
sudo pacman -S glibc
sudo pacman -S linux-apt-headers
```

bashrc

```shell
# ~/.bashrc
export C_INCLUDE_PATH="/lib/modules/$(uname -r)/build/include":$C_INCLUDE_PATH
export C_INCLUDE_PATH="/lib/modules/$(uname -r)/build/include/uapi":$C_INCLUDE_PATH
```

```shell
sudo pacman -S libx11
sudo pacman -S xorgproto
sudo pacman -S glfw
sudo pacman -S libgl
# sudo pacman -S mesa
# sudo pacman -S glu
```