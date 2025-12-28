#!/bin/bash

# ----------------------------------------
# Script de release pour libft
# Compile les tests, vérifie qu'ils passent
# puis crée un tag Git et le pousse sur GitHub
# ----------------------------------------

# 1️ Compiler les sources + tests
echo "📦 Compilation des sources et tests..."
gcc -Iinclude -Itest/include ./src/*.c ./test/*.c -o build/a.out

# Vérifier si la compilation a réussi
if [ $? -ne 0 ]; then
    echo "❌ Compilation échouée. Release aborted."
    exit 1
fi

# 2️ Exécuter les tests
echo "🧪 Lancement des tests..."
./build/a.out

# Vérifier si les tests ont réussi
if [ $? -ne 0 ]; then
    echo "❌ Tests échoués. Release aborted."
    exit 1
fi

# 3️ Demander la nouvelle version
read -p "Entrez la nouvelle version (ex: V1.0.0) : " version

# 4️ Créer un tag Git annoté
git tag -a "$version" -m "Release $version"

# 5️ Pousser le tag sur GitHub
git push origin "$version"

echo "✅ Release $version créée et poussée avec succès !"
