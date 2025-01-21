import xmlrpc.client

HOST = 'localhost'
SERVER_PORT = 8000
CLIENT_PORT = 9001
endereco_servidor = f"{HOST}:{SERVER_PORT}"
endereco_cliente = f"{HOST}:{CLIENT_PORT}"  # Host B usa 9001

with xmlrpc.client.ServerProxy(f"http://{endereco_servidor}") as server:
    server.registra_cliente(endereco_cliente)
    while True:
        mensagem = input("Digite a mensagem (ou 'exit' para sair): ")
        if mensagem.lower() == "exit":
            break
        msg = {
            "remetente": endereco_cliente,
            "texto": mensagem
        }
        resposta = server.processa_mensagem(msg)
        print(resposta)

with xmlrpc.client.ServerProxy(f"http://{endereco_cliente}") as server:
    server.register_function(lambda msg: print(f"Mensagem recebida de {msg['remetente']}: {msg['texto']}"), 'recebe_mensagem')
    print(f"Cliente iniciado em http://{endereco_cliente}")
    server.serve_forever()