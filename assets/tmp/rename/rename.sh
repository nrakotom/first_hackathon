counter=109
for file in $(ls *.xpm | sort); do
	new="${counter}.xpm"
	if [ -e "$new" ]; then
		exit 1
	fi
	mv "$file" "$new"
	counter=$((counter + 1))
done
