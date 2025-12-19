import pandas as pd

df = pd.read_csv("/content/heart.csv")
df.info()

# Quantidade de dados de cada classe
df.HeartDisease.value_counts()

# Análise de distribuição de classe por features
import seaborn as sb

sb.pairplot(df, hue="HeartDisease", size=2)

# Processamento de dados categóricos em dicionários
from sklearn.preprocessing import LabelEncoder

cols = [c for c in df.columns if df[c].dtype == "object"]
for c in cols:
    label_encoder = LabelEncoder()
    df[c] = label_encoder.fit_transform(df[c])
    mapping = {value: i for i, value in enumerate(label_encoder.classes_)}
    print(c, mapping)
df

# Separação dos dados de treino e teste por hold-out
from sklearn.model_selection import train_test_split

X = df.drop(columns=["HeartDisease", "RestingBP"])
# X = df.drop(columns = ['HeartDisease']) remove classe-alvo
y = df.HeartDisease

X_train, X_test, y_train, y_test = train_test_split(
    X,
    y,
    test_size=0.2,  # 20% dos dados para teste
    random_state=42,
)

# Treinamento de Classificação por Árvore de Decisão
from numpy import random
from sklearn.tree import DecisionTreeClassifier

model = DecisionTreeClassifier(max_depth=5, random_state=42)
model.fit(X_train, y_train)  # atributo-alvo, features

# Plotagem
import matplotlib.pyplot as plt
from sklearn.tree import plot_tree

plt.figure(figsize=(16, 8))
plot_tree(
    model, feature_names=X.columns, class_names=["0", "1"], rounded=True, filled=True
)
plt.show()

# Predição do modelo
y_pred = model.predict(X_test)

# Testagem
from sklearn.metrics import ConfusionMatrixDisplay, classification_report

print(classification_report(y_test, y_pred))
ConfusionMatrixDisplay.from_predictions(y_test, y_pred, cmap="Blues")

# Treinamento de Classificação por KNN
from numpy import random
from sklearn.neighbors import KNeighborsClassifier

knn_model = KNeighborsClassifier(n_neighbors=5)
knn_model.fit(X_train, y_train)  # atributo-alvo, features

y_pred = knn_model.predict(X_test)
