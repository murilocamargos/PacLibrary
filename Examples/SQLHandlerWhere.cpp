SQLHandler *sql = new SQLHandler();
sql->Table("usuarios")
   ->Where("login", "murilo")
   ->Where("nivel", "1")
   ->WhereOr("idade", "<", "20");

std::cout << sql->Select();
// SELECT * FROM usuarios WHERE nome = 'Murilo' AND nivel = '1' OR idade < '20'
