#! /usr/bin/bash
read -p "Enter the folder path: " folder_path

find "$folder_path" -type f -name 'bsse11*' | sort

