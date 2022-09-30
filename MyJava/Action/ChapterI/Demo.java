import java.sql.*;

public class Demo {
    static String url = "jdbc:mysql://localhost:3306/datascience";
    static String username = "root";
    static String password = "asdf8296776";
    static Connection conn = null;

    public static void main(String[] args) throws SQLException {
        //获取与数据库的链接
        conn = DriverManager.getConnection(url, username, password);
        //获取用于向数据库发送sql语句的statement
        PreparedStatement st;
        String sql = "select * from ?";
        //3.获取用于向数据库发送sql语句的PreparedStatement
        st = conn.prepareStatement(sql);
        //在此次传入，进行预编译
        st.setString(1, username);
        st.setString(2, password);
        //4.向数据库发sql
        st.executeQuery();//在这里不需要传入sql
    }
}