SQLHandler    *sql = new SQLHandler();
SQLiteHandler *db  = new SQLiteHandler();

sql->Table("usuarios")
   ->Where("user_id", "1");

db->Exec(sql->Delete());
// O seguinte comando SQL ser� executado no banco:
//   DELETE FROM usuarios WHERE user_id = '1'
