import com.mysql.jdbc.Driver;

import java.sql.*;

public class TestJDBC {
    static final String url = "jdbc:mysql://localhost:3306/mysql_learning?useUnicode=true&characterEncoding=UTF-8&userSSL=false&serverTimezone=GMT%2B8";  // 数据库 url
    static final String user = "root"; // 数据库用户名
    static final String password = "asdf8296776"; // 数据库密码
    public static void main(String[] args) throws SQLException, ClassNotFoundException {
        Class.forName("com.mysql.cj.jdbc.Driver");
        // 1. 加载数据库驱动
        DriverManager.registerDriver(new Driver());
        // 2. 建立连接
        Connection connection = DriverManager.getConnection(url, user, password);
        // 3. 创建 Statement 对象，用于向数据库发送 SQL 语句
        String sql = "SELECT * FROM customers";
        Statement statement = connection.createStatement();
        ResultSet resultSet = statement.executeQuery(sql);
        // 4. 获取 ResultSet 对象，取出数据，此对象代表结果集
        while (resultSet.next()) {
            int id = resultSet.getInt("cust_id");
            String username = resultSet.getString("cust_name");
            System.out.println("id=" + id + "; username=" + username + '\r');
        }
        // 5. 释放资源，断开与数据库的连接（调用close()方法）
        // 5.1 释放 ResultSet
        resultSet.close();
        // 5.2 释放 Statement
        statement.close();
        // 5.3 释放 Connection
        connection.close();
    }
}