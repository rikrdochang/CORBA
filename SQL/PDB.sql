-- MySQL dump 10.13  Distrib 5.5.48, for Win64 (x86)
--
-- Host: localhost    Database: PDB
-- ------------------------------------------------------
-- Server version	5.5.48

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `amigos`
--

DROP TABLE IF EXISTS `amigos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `amigos` (
  `correo1` varchar(100) NOT NULL,
  `correo2` varchar(100) DEFAULT NULL,
  KEY `correo1` (`correo1`),
  KEY `correo2` (`correo2`),
  CONSTRAINT `amigos_ibfk_1` FOREIGN KEY (`correo1`) REFERENCES `usuarios` (`correo`) ON UPDATE CASCADE,
  CONSTRAINT `amigos_ibfk_2` FOREIGN KEY (`correo2`) REFERENCES `usuarios` (`correo`) ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `amigos`
--

LOCK TABLES `amigos` WRITE;
/*!40000 ALTER TABLE `amigos` DISABLE KEYS */;
INSERT INTO `amigos` VALUES ('primero@correo.com','segundo@correo.com'),('primero@correo.com','tercero@correo.com'),('presedo2@correo.com','cuarto@correo.com'),('cuarto@correo.com','presedo2@correo.com');
/*!40000 ALTER TABLE `amigos` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pendiente`
--

DROP TABLE IF EXISTS `pendiente`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `pendiente` (
  `correo1` varchar(100) NOT NULL,
  `correo2` varchar(100) NOT NULL,
  PRIMARY KEY (`correo1`,`correo2`),
  KEY `correo2` (`correo2`),
  CONSTRAINT `pendiente_ibfk_1` FOREIGN KEY (`correo1`) REFERENCES `usuarios` (`correo`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `pendiente_ibfk_2` FOREIGN KEY (`correo2`) REFERENCES `usuarios` (`correo`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pendiente`
--

LOCK TABLES `pendiente` WRITE;
/*!40000 ALTER TABLE `pendiente` DISABLE KEYS */;
/*!40000 ALTER TABLE `pendiente` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `usuarios`
--

DROP TABLE IF EXISTS `usuarios`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `usuarios` (
  `correo` varchar(100) NOT NULL,
  `nombre` varchar(20) DEFAULT NULL,
  `pass` varchar(20) NOT NULL,
  PRIMARY KEY (`correo`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `usuarios`
--

LOCK TABLES `usuarios` WRITE;
/*!40000 ALTER TABLE `usuarios` DISABLE KEYS */;
INSERT INTO `usuarios` VALUES ('carlos@correo.com','Carlos','carlos'),('cuarto@correo.com','cuarto','aaaaaaaa'),('pepe@correo.com','Pepe','pepepe'),('presedo2@correo.com','Presedo2','presedinho'),('presedo@correo.com','Presedo','presedo'),('primero@correo.com','primero','primero'),('segundo@correo.com','segundo','segundo'),('tercero@correo.com','tercero','tercero');
/*!40000 ALTER TABLE `usuarios` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-04-16  0:28:23
