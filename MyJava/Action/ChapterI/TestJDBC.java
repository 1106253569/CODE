import java.sql.*;

public class TestJDBC {
    public static void main(String[] args)
            throws ClassNotFoundException, SQLException {
        //通过java访问mysql数据库
        //这个对象获取数据库链接
        //注册驱动，输入链接地址，用户名，密码
        String driver = "com.mysql.cj.jdbc.Driver";

        //访问本机的mysql数据库,格式 jdbc:数据库://本地端口3306/数据库名?跨时区参数
        String url = "jdbc:mysql://localhost:3306/mysql-db?serverTimezone=Asia/Shanghai";
        String username = "root";
        String password = "root";

        Class.forName(driver);

        //获取到数据库链接
        Connection connection = DriverManager.getConnection(url, username, password);

        //创建一个Statement语句对象
        Statement stat = connection.createStatement();

        //执行SQL语句
        String sql = "select * from student";

        //把查询的结果（表记录）存放到ResultSet对象中，结果集
        ResultSet resultSet = stat.executeQuery(sql);
    }
}
