import pandas as pd

df = pd.read_csv("alzheimer_data_processed_final_760.csv")
df.info()

df.Diagnosis.value_counts()
df.head()

# Análise de distribuição de classe por features
import seaborn as sb

sb.pairplot(df, hue="Diagnosis", size=2)

# Separação dos dados de treino e teste por hold-out
from sklearn.model_selection import train_test_split

y = df.Diagnosis
X = df.drop(
    columns=[
        "Diagnosis",
        "CholesterolTotal",
        "CholesterolHDL",
        "CholesterolLDL",
        "Gender",
        "Smoking",
        "DiastolicBP",
        "PhysicalActivity",
    ]
)

X_train, X_test, y_train, y_test = train_test_split(
    X, y, stratify=y, test_size=0.30, random_state=16
)

# Treinamento de Classificação por Árvore de Decisão
from numpy import random
from sklearn.tree import DecisionTreeClassifier

model = DecisionTreeClassifier(criterion="entropy", max_depth=5, random_state=16)
model.fit(X_train, y_train)

# Plotagem
import matplotlib.patches as mpatches
import matplotlib.pyplot as plt
from sklearn.tree import plot_tree

plt.figure(figsize=(48, 16))
plot_tree(
    model,
    feature_names=X.columns,
    class_names=["0", "1"],
    rounded=True,
    filled=True,
    fontsize=10,
)

legend_patches = [
    mpatches.Patch(color="lightcoral", label="0: Ausência de Alzheimer"),
    mpatches.Patch(color="skyblue", label="1: Presença de Alzheimer"),
]

plt.legend(handles=legend_patches, loc="upper right", title="Diagnosis Class")
plt.show()

# Predição do modelo
y_pred = model.predict(X_test)

# Gera as previsões no conjunto de treino
y_train_pred = model.predict(X_train)

# Metricas de Treino

from sklearn.metrics import classification_report

print(classification_report(y_train, y_train_pred))
ConfusionMatrixDisplay.from_predictions(y_train, y_train_pred, cmap="Oranges")

# Metricas de Teste
from sklearn.metrics import ConfusionMatrixDisplay, classification_report

print(classification_report(y_test, y_pred))
ConfusionMatrixDisplay.from_predictions(y_test, y_pred, cmap="Blues")
