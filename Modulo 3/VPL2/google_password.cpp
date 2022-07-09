#include "google_password.hpp"

#include <iostream>
#include <list>
#include <string>

static double constexpr _TAM_MIN = 6;
static double constexpr _TAM_MAX = 50;

void GooglePassword::insert(const std::string &url,
                            const std::string &login,
                            const std::string &password) //// insere uma nova senha associado a um determinado site
{
    // TODO: Implemente este metodo
    /**
   * Lembre-se que as credenciais so podem ser inseridas com as seguintes
   * condicoes:
   * Condicao 1: A senha nao pode ter a seguencia '123456'.
   * Condicao 2: A senha nao pode ter mais do que 50 caracteres (no maximo 50).
   * Condicao 3: A senha nao pode ter menos do que 6 caracteres (no minimo 6).
   * Condicao 4: A senha nao pode ter caracteres em branco ' '.
   *
   * Exemplos de senhas invalidas:
   * 123456
   * test_123456
   * 123456_test
   * test_123456_test
   * senha test
   */
    if (!checkPassword(password) == false)
    {
        m_passwords.insert(std::pair<std::string, Usuario>(url, Usuario(login, password)));
    }
}

void GooglePassword::remove(const std::string &url) //remove as informações associadas a um site
{
    // TODO: Implemente este metodo
    for (auto it = m_passwords.begin(); it != m_passwords.end(); it++)
    {
        if (it->first == url)
        {
            m_passwords.erase(it);
            break;
        }
    }
}

void GooglePassword::update(const std::string &url,
                            const std::string &login,
                            const std::string &old_password,
                            const std::string &password) //atualiza as credenciais utilizadas em um site
{
    // TODO: Implemente este metodo
    /**
   * Caso a url nao seja encontrada, o metodo update deve ser ignorado, ou seja,
   * este metodo nao pode inserir novas credenciais. Alem disso, as informacoes
   * do usuario so podem ser atualizadas se a senha antiga for igual a senha
   * atual. Nao esqueca de verificar se o novo password tambem e valido.
   */
    for (auto it = m_passwords.begin(); it != m_passwords.end(); it++)
    {
        if (it->first == url)
        {
            if (old_password == it->second.getPassword())
            {
                if (!checkPassword(password) == false)
                {
                    it->second.setPassword(password);
                    it->second.setLogin(login);
                }
            }
        }
    }
}

void GooglePassword::printPasswords() //imprime as informações salvas em ordem alfabética, utilizando os sites como critério de ordem
{
    // TODO: Implemente este metodo
    /**
   * Exemplo de saida:
   * www.site.com: login and password
   *
   */
    std::cout << m_passwords.size() << std::endl;
    for (auto it = m_passwords.begin(); it != m_passwords.end(); it++)
    {
        std::cout << it->first << ": " << it->second.getLogin() << " and " << it->second.getPassword() << std::endl;
    }
}

bool GooglePassword::checkPassword(const std::string &password) const // verifica se o password passa em todas as restricoes
{
    // TODO: Implemente este metodo
    std::list<std::string> test = {"123456", "test_123456", "123456_test", "senha test", "test_123456_test", " "}; //PQ se remover essa linha da erro em tudo

    for (auto it = m_passwords.begin(); it != m_passwords.end(); it++)
    {
        if (std::size_t found = password.find_first_of("123456") <= password.size() && password.find_first_of("6") <= password.size())
        {
            return false;
            break;
        }
        if (std::size_t found = password.find_first_of(" ") <= password.size())
        {
            return false;
            break;
        }
        if (it->second.getPassword() == password)
        {
            return false;
            break;
        }
        if (password.size() < 6)
        {
            return false;
            break;
        }
        if (password.size() > 50)
        {
            return false;
            break;
        }
        if (password.empty())
        {
            return false;
            break;
        }
        else
        {
            return true;
        }
    }
}