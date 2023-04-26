USE BD_PEDIDO
DROP TABLE tbCLIENTE 
-- As restri��es de remo��o se aplicam aos atributos, e n�o �s estruturas. Por isso, tbCliente n�o pode
-- ser removido por conta de ter refer�ncias em Foreign Keys, o que � muito diferente de excluir as refer�ncias em si.

ALTER TABLE tbPedido
	DROP CONSTRAINT FK__tbPedido__CLI_CO__412EB0B6

-- Agora sim � poss�vel remover a tabela tbCLIENTE, pois nenhuma Foreign Key se referencia � ela.