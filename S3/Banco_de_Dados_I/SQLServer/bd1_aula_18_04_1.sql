USE BD_PEDIDO
DROP TABLE tbCLIENTE 
-- As restrições de remoção se aplicam aos atributos, e não ás estruturas. Por isso, tbCliente não pode
-- ser removido por conta de ter referências em Foreign Keys, o que é muito diferente de excluir as referências em si.

ALTER TABLE tbPedido
	DROP CONSTRAINT FK__tbPedido__CLI_CO__412EB0B6

-- Agora sim é possível remover a tabela tbCLIENTE, pois nenhuma Foreign Key se referencia á ela.