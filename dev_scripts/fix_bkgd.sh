#!/bin/bash
# fix_bkgd.sh
# Finds all PNGs with invalid bKGD chunk and fixes them with pngcrush

echo "Scanning for bKGD warnings..."

# Find all offending files
WARNINGS=$(make -j1 2>&1 | grep -B1 "bKGD: invalid index" | grep "gbagfx" | grep -oP 'graphics/\S+\.png')

if [ -z "$WARNINGS" ]; then
    echo "No bKGD warnings found!"
    exit 0
fi

echo "Found these files:"
echo "$WARNINGS"
echo ""
echo "Fixing..."

for f in $WARNINGS; do
    echo "  fixing $f"
    pngcrush -rem bKGD -ow "$f" 2>/dev/null
done

echo ""
echo "Done. Re-run 'make -j$(nproc)' to confirm no warnings remain."